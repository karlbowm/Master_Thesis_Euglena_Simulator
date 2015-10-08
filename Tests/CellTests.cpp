#include <gtest/gtest.h>
#include <Cell.h>

/*Creation Tests*/
TEST(CellCreation,defaultConstructor)
{
    Cell def;
  
    EXPECT_FLOAT_EQ(0.0f, def.getStaticLightIntensity());
    EXPECT_FLOAT_EQ(0.0f, def.getDynamicLightIntensity());
    EXPECT_FLOAT_EQ(0.0f, def.getTotalIntensity());
    


}

TEST(CellCreation, staticLightConstructor)
{
    
    Cell def(33.0f);

    EXPECT_FLOAT_EQ(33.0f, def.getStaticLightIntensity());
    EXPECT_FLOAT_EQ(0.0f, def.getDynamicLightIntensity());
    EXPECT_FLOAT_EQ(33.0f, def.getTotalIntensity());
  

}



/* setter tests*/
TEST(CellSetters, setStaticLight)
{

    Cell def(33.0f);
    def.setStaticLightIntensity(91.0f);
    EXPECT_FLOAT_EQ(91.0f, def.getStaticLightIntensity());
    
}

TEST(CellSetters, setDynamicLight)
{

    Cell def(33.0f);
    def.setDynamicLightIntensity(22.0f);
    
    EXPECT_FLOAT_EQ(22.0f, def.getDynamicLightIntensity());
    
}


/*Getter tests*/
TEST(CellGetters, getStaticLight)
{
    Cell def(33.0f);
 
    EXPECT_FLOAT_EQ(33.0f, def.getStaticLightIntensity());    
}


TEST(CellGetters, getDynamicLight)
{
    Cell def(33.0f);
    def.setDynamicLightIntensity(11.0f);

    EXPECT_FLOAT_EQ(11.0f, def.getDynamicLightIntensity());
}

TEST(CellGetters, getTotalLight)
{
    Cell def(33.0f);
    def.setDynamicLightIntensity(23.0f);
    EXPECT_FLOAT_EQ(56.0f, def.getTotalIntensity());
}