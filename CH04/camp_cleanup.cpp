#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int main()
{
    std::ifstream inf("input.txt");
    std::string line;
    int match = 0;
    int matchSecond = 0;
    while (std::getline(inf,line))
    {
        std::stringstream ss(line);
        std::string s;
        std::vector<std::string> pairString;
        while(std::getline(ss,s,','))
        {
            pairString.push_back(s);
        }
        std::vector<int> points;
        for(auto v:pairString)
        {
            std::stringstream ssv(v);
            std::string sv;
            while(std::getline(ssv,sv,'-'))
            {
                points.push_back(std::stoi(sv));
            }
        }
        if( (points[0] == points[2]) || (points[1] == points[3]))
        {
            match++;
        }
        else if (points[0] < points[2]) // 2-9,3-12
        {
            if(points[1] > points[3])
                match++;
        }
        else if(points[0] > points[2])
        {
            if(points[3] > points[1])
                match++;
        }

        

        /* ============2nd Part */
        if( (points[0] == points[2]) || (points[1] == points[3]) || (points[1] == points[2]))
        {
            matchSecond++;
        }
        else if(points[0] < points[2])
        {
            if( (points[1] >= points[2]) )
            {
                matchSecond++;
            }
        }
        else if(points[0] > points[2])
        {
            if(points[3] >= points[0] )
                matchSecond++;
        }
        

    }

    std::cout<<match<<std::endl;
    std::cout<<matchSecond<<std::endl;

    return 0;
}