#include <gtest/gtest.h>
#include <Grid.h>

/*Creation Tests*/
TEST(GridCreation, simpleConstructor)
{
    Grid def(10,12);

    EXPECT_EQ(10, def.getImax());
    EXPECT_EQ(12, def.getJmax());

}


TEST(GridCreation, simpleConstructorWithLength)
{
    Grid def(10, 12,1.1f,14.0f);

    EXPECT_EQ(10, def.getImax());
    EXPECT_EQ(12, def.getJmax());
    EXPECT_FLOAT_EQ(1.1f, def.getWidth());
    EXPECT_FLOAT_EQ(14.0f, def.getHeight());

}


TEST(GridMethods, CoordinateConversionInGrid)
{
    Grid def(10, 10, 1.1f, 14.0f);
    //11x140

    auto result = def.convertCoordinateToIndex({ 10, 2.4f });
    EXPECT_EQ(9, result.x) << "First index was calculated wrong";
    EXPECT_EQ(0, result.y) << "Second index was calculated wrong";
}


TEST(GridMethods, CoordinateConversionOutSide)
{
    Grid def(10, 10, 1.1f, 14.0f);
    //11x140

    auto result = def.convertCoordinateToIndex({ 13, -1 });
    EXPECT_EQ(-1, result.x);
    EXPECT_EQ(-1, result.y);
}


//TODO: getters
TEST(GridGetters, getSimulationArea)
{
    Grid def(10, 10, 1.1f, 14.0f);
    //11x140
    
    auto result = def.getSimulationArea();
    EXPECT_FLOAT_EQ(11.0f, result.x);
    EXPECT_FLOAT_EQ(140.0f, result.y);
}
