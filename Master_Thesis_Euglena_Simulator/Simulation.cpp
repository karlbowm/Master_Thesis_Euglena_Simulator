#include "Simulation.h"
#include<algorithm>
#include "Log.h"
#include <iostream>


Simulation::Simulation(int i, int j) : _agentTemplate{{0,0}, 1.0, 0, 10},_width(i), _height(j)
{
    _agents.reserve(200);
    //TODO
}


Simulation& Simulation::setAgentTemplate(const EuglenaAgent& agentTemplate)
{
    _agentTemplate = agentTemplate;
    for (auto& emitter : _emitters)
        emitter.setAgentTemplate(_agentTemplate);


    return *this;
}

Simulation& Simulation::addEmitter(EuglenaEmitter emitter)
{
    emitter.setAgentTemplate(_agentTemplate);
    _emitters.push_back(emitter);

    return *this;
}


Simulation& Simulation::update(float deltaTime)
{
    //spawn new agents
    for (auto& emitter : _emitters)
        emitter.update(deltaTime, _agents);

    //move all agents
    for (auto it = _agents.begin(); it != _agents.end();)
    {
        it->clearPerception();
        for (auto& light :_lightLines)
        {
           
            auto inte = light.getLightIntensityAt(it->getPosition());
            if (inte > 1.0e-10)
            {

                auto d = light.getDirectionAt(it->getPosition());
                it->addIntensity(inte);
                it->addDirection(inte*glm::normalize(d));
            }
        }
        for(auto& light : _lightEmitters)
        {
            auto inte = light.getIntensity(_agents,it->getPosition());
            if (inte > 1.0e-10)
            {
                auto d = light.getDirectionAt(it->getPosition());
                it->addIntensity(inte);
                it->addDirection(inte*glm::normalize(d));
            }
        }

        it->update(_gravityVector, deltaTime);
       
        //Remove Agents outside of the Simulation
        if (isOutside(*it) || isInDestructor(*it))
        {
            it = _agents.erase(it);
            break;
        }
        ++it;
         
    }
    //update dynamic lights
    //std::cout << "Number of Agents: " << _agents.size() << "\n";
    return *this;
}

Simulation& Simulation::draw(sf::RenderWindow& renderWindow)
{
    //Render Grid
   

    //Render Emitter
    for (auto const& emitter : _emitters)
        emitter.draw(renderWindow);

    //Render Agents
    for (auto const& agent : _agents)
        agent.draw(renderWindow);


    //render lighta
    for (auto& light : _lightEmitters)
        light.draw(renderWindow);

    for (auto& light : _lightLines)
        light.draw(renderWindow);

  for (auto& destructor : _destructors)
        destructor.draw(renderWindow);

    return *this;
}

int Simulation::getScreenWidth() const
{
    return _width;
}

int Simulation::getScreenHeight() const
{
    return _height;
}



Simulation& Simulation::addAgent(const EuglenaAgent& agent)
{
    _agents.push_back(agent);
    return *this;
}

Simulation& Simulation::addLightEmitter(const DynamicLightEmitter& lightEmitter)
{
    _lightEmitters.push_back(lightEmitter);
    return *this;
}

Simulation& Simulation::addEuglenaDestructor(const EuglenaDestructor& eDestructor)
{
    _destructors.push_back(eDestructor);
    return *this;
}

Simulation& Simulation::addLightLine(const LightLine& lightLine)
{
    _lightLines.push_back(lightLine);
    return *this;
}

Simulation& Simulation::spawnAgentAt(glm::vec2 position)
{
    auto newAgent = EuglenaAgent{position,_agentTemplate.getIntensityThreshold(),_agentTemplate.getSpeed(),_agentTemplate.getRadius()};

    _agents.push_back(newAgent);
    return *this;
}







Simulation::~Simulation()
{
}

bool Simulation::isInDestructor(const EuglenaAgent& agent)
{
    for(auto &destructor : _destructors)
    {
        if(destructor.isInside(agent.getPosition()))
        {
            //std::cout << "Agent in destructor\n";
            return true;
        }
    }
    return false;
}

bool Simulation::isOutside(const glm::vec2& position) const
{
    glm::vec2 maxArea = { _width,_height };
    if (position.x > 0 && position.x < maxArea.x)
        if (position.y > 0 && position.y < maxArea.y)
            return false;

    return true;
}




bool Simulation::isOutside(const EuglenaAgent& agent) const
{
    auto position = agent.getPosition();
    glm::vec2 maxArea = { _width,_height };
    if (position.x > 0 && position.x < maxArea.x)
        if (position.y > 0 && position.y < maxArea.y)
            return false;

    return true;
}
