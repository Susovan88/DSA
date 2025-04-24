#include <iostream>
#include <cmath> 
#include <string>
#include <vector>
using namespace std;


// structure

class Gun{
public:
    int ammo;
    int damage;
    int scope=2;
};

class Player{ 
private:
    // data members...
    class Helmet{
        int hp;
        int level;
    public:
        void setHp(int hp){
            this->hp=hp;
        }
        void setLevel(int level){
            this->level=level;
        }
        int getHp(){
            return hp;
        }
        int getLevel(){
            return level;
        }
    };
    int health=200; 
    int score=0;
    bool alive=true;
    Gun gun; // gun object
    Helmet helmet; // Helmet object

public:
    // member functions...
    // setters...
    void setHealth(int health){
        this -> health=health;
    }
    void setScore(int score){
        this->score=score;
    }
    void isAlive(bool alive){
        this ->alive=alive;
    }
    void setGun(Gun gun){
        this->gun=gun;
    }
    // getters
    int getHeath(){
        return health;
    }
    int getScore(){
        return score;
    }
    bool getIsAlive(){
        return alive;
    }
    Gun getGun(){
        return gun;
    }
    void setHelmet(int level){
        Helmet *helmet=new Helmet;
        helmet->setLevel(level);
        int h=0;
        if(level==1)h=25;
        else if(level==2) h=50;
        else if (level==3) h=100;
        else cout<<"Invalid level of helmet."<<endl;

        helmet->setHp(h);
        this->helmet=*helmet;
    }
    void showHelmet(){
        cout<<"Helmet hp -"<<helmet.getHp()<<" level- "<<helmet.getLevel()<<endl;
    }
};

class Calculate{
private:
    int a=20;
    int b=9;

public:
    void Sum(int x,int y){
        a=x;
        b=y;
        cout<<a+b<<endl;
    }
    void Sub(int x,int y){
        a=x;
        b=y;
        cout<<a-b<<endl;
    }
};

int getMaxhelth(Player a, Player b){
    if(a.getHeath()>b.getHeath()) return a.getHeath();
    return b.getHeath();
}

Player getMaxScorePlayer(Player a, Player b){
    if(a.getScore()>b.getScore()) return a;
    return b;
}

int main() {
    vector<Player>players;  // array of objects...

    Player Susovan;  // object // static memeory alocation
    cout<<Susovan.getScore()<<" "<<Susovan.getHeath()<<endl;
    Susovan.setHealth(70);
    Susovan.setScore(20);
    Susovan.isAlive(true);

    Gun awm;
    awm.ammo=6;
    awm.damage=150;
    awm.scope=8;
    Susovan.setGun(awm);

    Susovan.setHelmet(3);

    players.push_back(Susovan);
    // cout<<"helth - "<<Susovan.getHeath()<<" score- "<<Susovan.getScore()<<" gun damage - "<<Susovan.getGun().damage<<" gun scope - "<<Susovan.getGun().scope<<endl;

    Player Pupai; // static memeory alocation
    Pupai.setHealth(99);
    Pupai.setScore(21);
    Pupai.isAlive(false);
    Pupai.setHealth(2);

    Gun ak;
    ak.ammo=6;
    ak.damage=150;
    ak.scope=4;
    Pupai.setGun(ak);

    Pupai.setHelmet(2);

    players.push_back(Pupai);

    // cout<<"max health is - "<<getMaxhelth(Susovan, Pupai)<<endl;;

    // Player s=getMaxScorePlayer(Susovan,Pupai);
    // cout<<"max score is - "<<s.getScore()<<endl;

    // Calculate cal; // static memeory alocation
    // cal.Sub(23,8);
    // cal.Sum(1,9);

    Player *avi=new Player;  // dynamic memeory alocation..
    (*avi).setHealth(89);
    (*avi).setScore(2);
    avi->setHelmet(1);
    // cout<<(*avi).getHeath()<<" "<<(*avi).getScore()<<endl;

    avi->setHealth(90);
    avi->setScore(12);
    players.push_back((*avi));
    // cout<<avi->getHeath()<<" "<<avi->getScore()<<endl;


    Player Mimi;
    Mimi.setHealth(200);
    Mimi.setScore(23);
    Mimi.setGun(awm);
    Mimi.setHelmet(3);

    players.push_back(Mimi);
    int i=1;

     cout<< " All Players in Free Fire-"<<endl<<endl;

    for( Player p : players){
        cout<<"=> => player "<<i;
        cout<<"  health "<<p.getHeath()<<" , score - "<<p.getScore()<<"', alive - "<<p.getIsAlive()<<endl;
        cout<< " Gum ->  ammo - "<<p.getGun().ammo<<" damage - "<<p.getGun().damage<<" scope - "<<p.getGun().scope<<"X"<<endl;
        p.showHelmet();
        cout<<endl;
        i++;
    }

}