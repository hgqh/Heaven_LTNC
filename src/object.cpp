#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>

#include"object.h"


void Object:: setDest(int x, int y, int w ,int h){
    dest.x=x;
    dest.y=y;
    dest.w=w;
    dest.h=h;
}
    void Object:: setSource (int x,int y, int w ,int h){
        src.x=x;
        src.y=y;
        src.w=w;
        src.h=h;
    }
    void Object:: setImage(string filename,SDL_Renderer* renderer){
        SDL_Surface* surf=IMG_Load(filename.c_str());
        tex=SDL_CreateTextureFromSurface(renderer,surf);
    }
