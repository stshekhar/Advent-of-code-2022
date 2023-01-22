#include <fstream>
#include <iostream>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <set>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <vector>

int main()
{
    std::ifstream inf("input.txt");
    std::string line;

    std::unordered_map<char,int> letters;
    for(int i=0;i<26;i++)
    {
        letters['a'+i] = i+1;
    }
    
    for(int i=0;i<26;i++)
    {
        letters['A'+i] = i+26+1;
    }



    std::unordered_map<char,int> priorityItem;
    while(std::getline(inf,line))
    {
        int length = line.length();
       
        std::string firstHalf = line.substr(0,length/2);
        std::string secondHalf = line.substr(length/2);
    
        std::unordered_set<char> firstHalfSet;
        for(auto x:firstHalf)
        {
            firstHalfSet.insert(x);
        }

        for(auto s:secondHalf)
        {
           if(firstHalfSet.find(s) != firstHalfSet.end())
           {
                priorityItem[s] += letters[s];
                break;
           } 
        }

    }
    int sumMax = 0;
    for(auto x:priorityItem)
    {
        sumMax += x.second;
        //std::cout<<x<<std::endl;
    }
   std::cout<<sumMax<<std::endl;

   int num_lines = 1;
   line.clear();
   std::vector<std::string> lines;
   std::vector<char> commonLetter;
   int sumIntersect = 0;
   inf.close();
   std::ifstream infNew("input.txt");
   while(std::getline(infNew,line))
   {
        lines.push_back(line);
        std::cout<<line<<std::endl;
        if(num_lines == 3)
        {
            std::unordered_map<char,int> ht;
            num_lines = 1;
          
            for(auto l:lines) //Create 3 set of group. 
            {
                
                std::set<char> group;    
                for(auto c:l) //find unique character
                {
                  group.insert(c);   
                }
                for(auto g:group) //count each unique character
                {
                    ht[g]++;
                }

            }

            for(auto h:ht) //check if one instance of each character is present in each group.
            {
                if(h.second == 3)
                {
                    sumIntersect += letters[h.first];
                }
            }

            lines.clear();
        }
        else
        {
            num_lines++;
        }
   }
    // auto sum = std::accumulate(priorityItem.begin(),priorityItem.end(),0);
    //std::cout<<sum<<std:endl;//First Answer
     std::cout<<sumIntersect<<std::endl; // 2nd Answer.
    return 0;
}


