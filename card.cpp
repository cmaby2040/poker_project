#include<iostream>
#include<string>
using namespace std;
//this class is finished
class Card{
    int value;
    char face_value;
    char suit;
    public:
    Card (int val);
    Card();
    int getValue();
    void setValue(int val);
    char getFace();
    void setFace(char val);
    char getSuit();
    void setSuit(char val);
    void printCard();
    bool operator==(const Card &c);
    bool operator<=(const Card &c);
    bool operator>=(const Card &c);
};

Card::Card(int val){
    suit='H';
    value=val;
    switch (val)
    {
    case 14:
        face_value='A';
        break;
    case 2:
        face_value='2';
        break;
    case 3:
        face_value='3';
        break;
    case 4:
        face_value='4';
        break;
    case 5:
        face_value='5';
        break;
    case 6:
        face_value='6';
        break;
    case 7:
        face_value='7';
        break;
    case 8:
        face_value='8';
        break;
    case 9:
        face_value='9';
        break;
    case 10:
        face_value='0';
        break;
    case 11:
        face_value='J';
        break;
    case 12:
        face_value='Q';
        break;
    case 13:
        face_value='K';
        break;
    }

}
Card::Card(){
    value=14;
    face_value='A';
    suit='C'; // 'C', 'D', 'H', 'S' || Smallest to Largest. there is a way to do the way i want it.

}
    int Card::getValue(){
        return value;
    }
    void Card::setValue(int val){
        value=val;
    }
    char Card::getFace(){
        return face_value;
    }
    void Card::setFace(char val){
        face_value= val;
    }
    void Card::printCard(){
        cout<< "\n_______" << "\n|" << suit << "    |"  << "\n|  " << face_value<< "  |" << "\n|     |"  << "\n-------";

    }

        char Card::getSuit(){
            return suit;
        }
        void Card::setSuit(char val){
            suit=val;
        }
        bool Card::operator==(const Card &c){
            if(((this->face_value)==c.face_value) && (this->suit==c.suit)){
                return true;
            }
            return false;
        }
        bool Card::operator<=(const Card &c){
            if((*this)==c){
                return true;
            }
            if(this->suit<=c.suit){
                if(this->value<c.value){
                    return true;
                }
                return false;
            }
            return false;
        }
        bool Card::operator>=(const Card &c){
            if(*(this)==c){
                return true;
            }
            if(this->suit>=c.suit){
                if(this->value>c.value){
                    return true;
                }
                return false;
            }            
            return false;
        }
