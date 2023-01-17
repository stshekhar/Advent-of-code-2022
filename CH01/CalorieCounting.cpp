#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
//#include <ifstream>


int main()
{
    std::ifstream inf("input.txt");

    std::vector<int> elfCalories;
    int currentSum = 0;
    int value = 0;
    while(inf)
    {
        std::string input;
        std::getline(inf,input);
        if( input.empty() )
        {
            elfCalories.push_back(currentSum);
            currentSum = 0;
        }
        else
        {
            currentSum += stoi(input);
        }


    }
    elfCalories.push_back(currentSum);
    // for(auto v:elfCalories)
    // {
    //     std::cout<<v<<std::endl;
    // }

    /*====================Part One========================*/
    auto max = std::max_element(elfCalories.begin(),elfCalories.end());
    //auto maxValue = std::max(elfCalories.begin(),elfCalories.end());
    std::cout<< "Max elfCalorie is: "<<*max<<std::endl;

    /*====================Part two========================*/
    std::priority_queue<int,std::vector<int>,std::greater<int>> pq;
    for(auto v:elfCalories)
    {
        pq.push(v);
        if(pq.size() > 3)
        {
            pq.pop();
        }
    }
    
   int sum = 0; 
   while(!pq.empty())
   {
    sum += pq.top();
    pq.pop();
   }
   std::cout<<sum<<std::endl;

return 0;
}