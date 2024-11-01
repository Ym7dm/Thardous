#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout<<"<{ ---Thrarduous--- }>"<<endl;
    string play;

    do
    {
        cout<<"[Choose Your Options] "<<endl<<
             "- Play"<<endl<<
             "- Exit"<<endl;
        cin>>play;
    }
    while(play!="play"&&play!="exit");

    while(play=="play")
    {
        //attributes that are not to mess with for the increase of their stats in each level
        int level=1, UserHealth=100, SwordAttack=15, ShieldUses=3,
            MonsterAttack=10, MonsterHealth=100;

        cout<<endl<<"{ -Instructions- }"<<endl
        <<"you will be facing a monster in 3 different levels!"<<endl
        <<"each level, you and the monster have equal health that increases with each level 50+ health."<<endl
        <<"monster's base attack DMG is 10 and yours with the sword is 15 and both increase by 5+ each level."<<endl
        <<"monster's attack increases by 5+ up to 35 DMG during the level if not using shield to reset buff stacks."<<endl
        <<"the shield negates all damage from the monster's next turn after shielding."<<endl
        <<"the next monster turn will hava a base damage of 15."<<endl
        <<"If you understood, enjoy playing!"<<endl<<endl;

        while(level<=3)
        {
            //current level attributes
            int user_health=UserHealth, sword_attack=SwordAttack,
                shield_uses=ShieldUses, monster_attack=MonsterAttack, monster_health=MonsterHealth;

            cout<<endl<<"-- LEVEL "<<level<<" --"<<endl<<
                 "Monster ["<<monster_health<<"]"<<endl<<
                 "Adventurer [You] ["<<user_health<<"]"<<endl;

            string start;
            do
            {
                cout<<endl<<"When You Are Ready Press start"<<endl;
                cin>>start;
                cout<<endl;
            }
            while(start!="start");

            string choose;
            while(monster_health>0 && user_health>0)
            {
                do
                {
                    cout<<endl<<"Your turn"<<endl<<"- Sword"<<endl<<
                         "- Shield ["<<shield_uses<<" Uses]"<<endl;
                    cin>>choose;
                }
                while(choose!="sword" && choose!="shield");

                if(shield_uses<=0 && choose=="shield")
                {
                    cout<<"Cannot use shield."<<endl;
                    continue;
                }

                if(choose=="sword")
                {
                    monster_health-=sword_attack;
                    cout<<endl<<"Hit!"<<endl<<"You did "<<sword_attack<<" DMG"<<endl<<
                         "Monster ["<<monster_health<<"]"<<endl <<
                         "Adventurer [You] ["<<user_health<<"]"<<endl;

                    if(monster_health<=0)break;

                    string continue_attack;
                    cout<<endl<<"Monster's Turn"<<endl;
                    do
                    {
                        cout<<"Press continue"<<endl;
                        cin>>continue_attack;
                        cout<<endl;
                    }
                    while(continue_attack!="continue");

                    user_health-=monster_attack;

                    cout<<"Hit!"<<endl<<"Monster did "<<monster_attack<<" DMG"<<endl<<
                         "Monster ["<<monster_health<<"]"<<endl<<
                         "Adventurer [You] ["<<user_health<<"]"<<endl;
                    if(user_health<=0)break;
                    if(monster_attack<35)monster_attack+=5;

                }
                else if(choose=="shield")
                {
                    monster_attack=0;
                    shield_uses--;
                    cout<<endl<<"Protected!"<<endl;

                    cout<<endl<<"Monster's Turn"<<endl;

                    string continue_attack;
                    do
                    {
                        cout<<"Press continue"<<endl;
                        cin>>continue_attack;
                        cout<<endl;
                    }
                    while(continue_attack!="continue");

                    user_health-=monster_attack;

                    cout<<"Monster's Turn"<<endl<<
                         "Hit!"<<endl<<"Monster did "<<
                         monster_attack<<" DMG" <<endl<<
                         "Monster ["<<monster_health <<"]"<<endl<<
                         "Adventurer [You] ["<< user_health <<"]"<<endl;
                    monster_attack=15;
                }
            }
            if(monster_health<=0)
            {
                cout<<"You Win!"<<endl;
                if(level<3)
                {
                    char next;
                    do
                    {
                        cout<<endl<<"- Continue to next level? (Y/N)"<<endl;
                        cin>>next;
                    }
                    while(next!='y' && next!='Y' && next!='N' && next!='n');

                    if(next=='N' || next=='n')break;
                    else if(next=='Y' || next=='y')
                    {
                        level++;
                        // Update  level attributes
                        UserHealth+=50;
                        SwordAttack+=5;
                        ShieldUses++;
                        MonsterHealth+=50;
                        MonsterAttack+=5;
                    }
                }
                else
                {
                    cout<<"Congratulations! You have completed all levels!"<<endl;
                    play="exit";
                    break;
                }
            }
            else if(user_health<=0)
            {
                cout<<"You Lost!"<<endl;
                char retry;
                do
                {
                    cout<<"- Retry level? (Y/N)"<<endl;
                    cin>>retry;
                }
                while(retry!='Y' && retry!='y' && retry!='N' && retry!='n');
                if(retry=='N' || retry=='n')
                    break;
                else if(retry=='Y' || retry=='y')
                {
                    // Reset current level attributes to initial value
                    user_health=UserHealth;
                    sword_attack=SwordAttack;
                    shield_uses=ShieldUses;
                    monster_health=MonsterHealth;
                    monster_attack=MonsterAttack;
                }
            }
        }
        // main menu
        do
        {
            if(level==3)break;
            cout<<"[Choose Your Options] "<<endl<<"- Play"<<
            endl<<"- Exit"<<endl;
            cin>>play;
        }
        while(play!="play" && play!="exit");
    }
    return 0;
}
