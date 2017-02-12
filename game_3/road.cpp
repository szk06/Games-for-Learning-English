#include "road.h"

road::road(bool x)
{
    ishorizontal =x;
    if(x==true){
        setPixmap(QPixmap("img3/horizontal.png").scaled(100,500));

    }else{
        setPixmap(QPixmap("img3/rect.png").scaled(100,200));
    }
}
