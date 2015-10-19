#include <gtest/gtest.h>
#include <EuglenaAgent.h>


/* Tests for the agent creation*/
TEST(AgentCreation, setPosition)
{
    glm::vec2 pos{ -2.0f,2.0f };


    EuglenaAgent agent(pos, 10.0f, 2.0f, 3.0f);
    auto result = agent.getPosition();
    EXPECT_FLOAT_EQ(pos.x, result.x) << "X Position is wrong";
    EXPECT_FLOAT_EQ(pos.y, result.y)<< "Y Position is wrong ";
}

TEST(AgentCreation, setThreshold)
{
    EuglenaAgent agent({ -2.0f,2.0f }, 10.0f, 2.0f, 3.0f);
    EXPECT_FLOAT_EQ(10.0f, agent.getIntensityThreshold());
}
TEST(AgentCreation, setSpeed)
{
    EuglenaAgent agent({ -2.0f,2.0f }, 10.0f, 2.0f, 3.0f);
    EXPECT_FLOAT_EQ(2.0f, agent.getSpeed());
}
TEST(AgentCreation, setSize)
{
    EuglenaAgent agent({ -2.0f,2.0f }, 10.0f, 2.0f, 3.0f);
    EXPECT_FLOAT_EQ(3.0f, agent.getRadius());
}


/*Tests for the setters*/

TEST(AgentSetters, setGradient)
{
    EuglenaAgent agent({ 1.0f,1.0f }, 10.0f, 2.0f, 3.0f);
    agent.setGradient(glm::vec2(-3.0f, 5.0f),false);
    EXPECT_FLOAT_EQ(glm::vec2(-3.0f, 5.0f).x, agent.getGradient().x);
    EXPECT_FLOAT_EQ(glm::vec2(-3.0f, 5.0f).y, agent.getGradient().y);
}

TEST(AgentSetters, setPosition)
{
    EuglenaAgent agent({ 1.0f,1.0f }, 10.0f, 2.0f, 3.0f);
    agent.setPosition({ -2.0,5.0 });
    EXPECT_FLOAT_EQ(glm::vec2(-2.0f, 5.0f).x, agent.getPosition().x);
    EXPECT_FLOAT_EQ(glm::vec2(-2.0f, 5.0f).y, agent.getPosition().y);
}


/*Behaviour test*/
TEST(AgentUpdate, positionCalculationBelowThreshold)
{
    EuglenaAgent agent({ 1.0f,1.0f }, 10.0f, 2.0f, 3.0f);
    agent.setGradient(glm::vec2(-4.0f, 6.0f), false);
    float timestep = 2.0f;
    float speed = 2.0f;
    auto posShift = glm::normalize(glm::vec2(-4.0f, 6.0f))*timestep*speed;
    agent.update(timestep, 20);
    EXPECT_FLOAT_EQ(1.0f + posShift.x, agent.getPosition().x);
    EXPECT_FLOAT_EQ(1.0f + posShift.y, agent.getPosition().y);
}


TEST(AgentUpdate, positionCalculationAboveThreshold)
{
    EuglenaAgent agent({ 1.0f,1.0f }, 10.0f, 2.0f, 3.0f);
    agent.setGradient(glm::vec2(-4.0f, 6.0f), false);
    float timestep = 2.0f;
    float speed = 2.0f;
    auto posShift = glm::normalize(glm::vec2(-4.0f, 6.0f))*timestep*2.0f;
    agent.update(timestep, 5);
    EXPECT_FLOAT_EQ(1.0f - posShift.x, agent.getPosition().x);
    EXPECT_FLOAT_EQ(1.0f - posShift.y, agent.getPosition().y);
}