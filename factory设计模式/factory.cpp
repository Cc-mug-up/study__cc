#include "factory.h"
int main()
{
    Shape *shape1 = ShapeFactory<Circle>::create();
    shape1->draw();
    Shape *shape2 = ShapeFactory<Rectangle>::create();
    shape2->draw();
}