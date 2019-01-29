#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void checkSurvival(int i) //To print your death message.
{
    if(i == 0) //If survived.
    {
        cout << "You survived for now..." << endl;
    }
    else //IF died.
    {
        cout << "R.I.P." << endl;
    }
}

int main()
{
    bool dead = false;
    int slot, player = 1;
    const int BULLET_POS = 2; //Unchangable do to request.

    srand(time(0)); //Changes seed every secound.

    while(dead == false) //Game only works while alive.
    {
        slot = (rand() % 6) + 1; //What slot will be fired.

        cout << "Press 'Enter' to pull trigger...";
        cin.ignore(); //We only need a non-spesific input.

        if(BULLET_POS != slot) //If bullet was not shot.
        {
            cout << "*click*" << endl;
            checkSurvival(0);
            if(player == 1) //If Player 1 finished last.
            {
                player++;
            }
            else //If player 2 finished last.
            {
                player--;
            }

            cout << "Player "<< player <<": your turn." << endl;
        }
        else //If bullet was shot.
        {

            cout << "BANG!!!" << endl;
            checkSurvival(1);
            dead = true; //Ends game.
        }
    }

    cout << "Player "<< player <<" died..." << endl; //Game ending message.
}
