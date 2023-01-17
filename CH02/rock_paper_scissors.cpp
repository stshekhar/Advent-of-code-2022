#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
//#include <pair>
#include <vector>
#include <unordered_map>

std::unordered_map<char,char> winningCombination;
std::unordered_map<char,int> score;
int main()
{
    // GAMEPOINT A{rock};
    // GAMEPOINT X{rock};
    // GAMEPOINT B{paper};
    // GAMEPOINT Y{paper};
    // GAMEPOINT C{scissor};
    // GAMEPOINT Z{scissor};  

    
   
    score['X'] = 1;
    score['Y'] = 2;
    score['Z'] = 3;

    score['A'] = 1;
    score['B'] = 2;
    score['C'] = 3;


    std::ifstream inf("input.txt");
    std::vector<std::pair<char,char>> result;
    std::string line;

    while(std::getline(inf,line))
    {
      
        std::stringstream ss(line);
        char player1,player2;
        ss>>player1;
        ss>>player2;
        ss.clear();
        result.push_back({player1,player2});

    }
    
    int sum = 0;
    
    /*===============Part1========================*/
    winningCombination['C'] = 'X';
    winningCombination['B'] = 'Z';
    winningCombination['A'] = 'Y';



    for(auto v:result)
    {
        //std::cout<<v.first<<" "<<v.second<<std::endl;
        if(winningCombination[v.first] == v.second) //Do we have winning combination.
        {
            sum += score[v.second]+6; 
        }
        else //We haven't won. So either Draw or loss.
        {
            if(score[v.first] == score[v.second]) //Draw
            {
                sum += score[v.second]+3;
            }
            else //Loss
            {
                sum += score[v.second];
            }

        }
          
    }  

    std::cout<<sum<<std::endl;

    /*===============Part2========================*/
    std::unordered_map<char,char> loosingCombination;

    loosingCombination['A'] = 'C';
    loosingCombination['C'] = 'B';
    loosingCombination['B'] = 'A';

    sum = 0;
    for(auto v:result)
    {
        if(v.second == 'X') //Need to loose
        {
            sum += score[loosingCombination[v.first]];
        }
        else if(v.second == 'Y') //Need to draw
        {
            sum += score[v.first] + 3;
        }
        else //Need to win
        {
            sum += score[winningCombination[v.first]] + 6;
        }
    }

    std::cout<<sum<<std::endl;

    return 0;
}