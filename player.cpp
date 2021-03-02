#include"Card.cpp"
#include<vector>
#include<tuple>// this will be later when finishing the 
// shout out to
using namespace std;
class Player{
    //what structure to use here? vector or individual objects?
    Card first, second; // better to have them here so i know the card for the unsorted array
    //int suitArray[]= {0,0,0,0}; // C,D,H,S
    Card playerCards[7];
    bool isFlush;
    bool isStraight;
    //vector<Card> outs;
    // there is more here to add
    // player focused here. you can bet with computers and shit.
    // here it doesnt really matter how you do it start here to calcuate the odds an out for each indivd
    public:
    Card getFirst();
    Card getSecond();
    void setFirst(Card &frst);
    void setSecond(Card &secnd);
    void setFlush(Card &f1, Card &f2, Card &f3);
    void setRiver(Card &r1);
    void setTurn(Card &t1);
    Player();
    int winningHand(Card array[7]);
    // checks in order for the winning hand. (this might need to be copied)
    // there has to be a method that resest everything at the end of the turn.
    // sort the cards first. make it 5 million times easier go back to the website. 
    bool royalFlush(Card array[7]);//sorted deck order suit 1
    bool straightFlush(Card array[7]); //2
    bool flush(Card array[7]); //5 sorted by suit only 
    
    bool fullhouse(Card array[7]); //4 ask about this one. idea: pass in the first five elements into the function some how.

    bool fourOfKind(Card array[7]);  //3 sorted by rank only below
    bool straight(Card array[7]); //6
    bool ThreeOfAKind(Card array[7]); //7
    bool TwoPair(Card array[7]);    //8
    bool pair(Card array[7]); //9
    Card highCard(Card array[7]);                     //10
    void sortRank();
    void sortSuit(); 
    
    void printPlayersCards();
    Card* getArrayPointer() { return playerCards; }
    //void highCard(); this might not be needed it is the last option always true.
    // fix the set value for the cards.
};

    Card Player::getFirst(){
        return first;
    }
    Card Player::getSecond(){
        return second;
    }
    void Player::setFirst(Card &frst){
        playerCards[0]=frst;
        first=frst;

    }
    void Player::setSecond(Card &secnd){
       playerCards[1]=secnd;
       second=secnd;
    }
    void Player::setFlush(Card &f1, Card &f2, Card &f3){
        playerCards[2]=f1;
        playerCards[3]=f2;
        playerCards[4]=f3;
        /*
        auto it = playerCards.emplace ( playerCards.begin()+2, f1);
        playerCards->emplace(playerCards.begin()+1, f2);
        playerCards->emplace(playerCards.begin()+1, f3);
        it = playerCards->begin();
        */
    }
    void Player::setRiver(Card &r1){
        playerCards[5]=r1;
    }
    void Player::setTurn(Card &t1){
        playerCards[6]=t1;

    }
    Player::Player(){
        for(int j=0;j<7;++j){
            Card i;
            playerCards[j]=i;
        }
        isStraight=false;
        isFlush=false;
    }
    int Player::winningHand(Card array[7]){// int checks to see that the highest rated hand.
                                           // will have to do another check if some are the same result.
        /*
        sort by suit for the flush(){flush , straighflush and royal flush}
        start with a flush check(if true look for the royal flushstore flush in data)
        sort by rank 
        look for the straight check( check for the flush change to see the stright flush)
        continue on as normal ()
        for the rest except for the full house to find the winner.
        */
        this->sortSuit();
        if(this->flush(array)){
            if(this->royalFlush(array)){
                return 10; //return values as enumerations. or change them to ints.
            }
            isFlush = true;
        }
        this->sortRank();
        if(this->straight(array)){
            if(isFlush==true){
                return 9;//  2
            }
            isStraight = true;
        }
        if(this->fourOfKind(array)){
            return 8; // 3
        }
        if(this->fullhouse(array)){//sorted by rank 
            return 7; //4 
        }
        if(isFlush==true){
            return 6; //5
        }
        if(isStraight==true){
            return 5; //6
        }
        if(this->ThreeOfAKind(array)){
            return 4; //7
        }
        /*
        if(this->twoPair(array)){
            return 3; //8
        }
        */
        if(this->pair(array)){
            return 2; //9
        }
        return 1; //10
        

    }    
    bool Player::flush(Card array[7]){ //done 
        bool a1 =0,a2=0,a3=0;
        Card* p= array;   
        
        a1= ((p->getSuit()==(p+1)->getSuit())&&
        ((p+1)->getSuit()==(p+2)->getSuit())&&
        ((p+2)->getSuit()==(p+3)->getSuit())&&
        ((p+3)->getSuit()==(p+4)->getSuit()));

        a2= (((p+1)->getSuit()==(p+2)->getSuit())&&
        ((p+2)->getSuit()==(p+3)->getSuit())&&
        ((p+3)->getSuit()==(p+4)->getSuit())&&
        ((p+4)->getSuit()==(p+5)->getSuit()));
        
        a3= (((p+2)->getSuit()==(p+3)->getSuit())&&
        ((p+3)->getSuit()==(p+4)->getSuit())&&
        ((p+4)->getSuit()==(p+5)->getSuit())&&
        ((p+5)->getSuit()==(p+6)->getSuit()));
        
        return (a1 || a2 || a3);      
    }
    
    bool Player::royalFlush(Card array[7]){//    done 
       if(!(this->flush(array))){//check for a flush needs a sorted array by suit.
           return false;
       }
       Card *p = array;
       bool a1,a2,a3;
       cout << "leave flush check" << endl;
        if(p->getFace()=='A'){ //each of these check the argument. 
            a1 = (((p+1)->getFace()=='K')&&
            ((p+2)->getFace()=='Q')&&
            ((p+3)->getFace()=='J')&&
            ((p+4)->getFace()=='0'));

        }if((p+1)->getFace()=='A'){

            a2 = (((p+2)->getFace()=='K')&&
            ((p+3)->getFace()=='Q')&&
            ((p+4)->getFace()=='J')&&
            ((p+5)->getFace()=='0'));

        }if((p+2)->getFace()=='A'){
            a3 = (((p+3)->getFace()=='K')&&
            ((p+4)->getFace()=='Q')&&
            ((p+5)->getFace()=='J')&&
            ((p+6)->getFace()=='0'));

        }
        return (a1||a2||a3);
            
    }

    bool Player::fourOfKind(Card array[7]){ // sorted by rank() should also make this const pointer.
        Card* p =array;
        bool a1,a2,a3,a4;

        a1=((p->getValue()==(p+1)->getValue())&&
        ((p+1)->getValue()==(p+2)->getValue())&&
        ((p+2)->getValue()==(p+3)->getValue()));

        a2=(((p+1)->getValue()==(p+2)->getValue())&&
        ((p+2)->getValue()==(p+3)->getValue())&&
        ((p+3)->getValue()==(p+4)->getValue()));

        a3=(((p+2)->getValue()==(p+3)->getValue())&&
        ((p+3)->getValue()==(p+4)->getValue())&&
        ((p+4)->getValue()==(p+5)->getValue()));

        a4=(((p+3)->getValue()==(p+4)->getValue())&&
        ((p+4)->getValue()==(p+5)->getValue())&&
        ((p+5)->getValue()==(p+6)->getValue()));

        return (a1||a2||a3||a4);
    }
    bool Player::fullhouse(Card array[7]){
        return true;
    }
    bool TwoPair(Card array[7]){
        return false;
    }
    bool Player::straight(Card array[7]){//  done 
        Card* p =array;
        bool a1,a2,a3;

        a1=(((p+1)->getValue()==((p)->getValue()-1))&&
        ((p+2)->getValue()==((p+1)->getValue()-1))&&
        ((p+3)->getValue()==((p+2)->getValue()-1))&&
        ((p+4)->getValue()==((p+3)->getValue()-1)));


        a2=(((p+2)->getValue()==((p+1)->getValue()-1))&&
        ((p+3)->getValue()==((p+2)->getValue()-1))&&
        ((p+4)->getValue()==((p+3)->getValue()-1))&&
        ((p+5)->getValue()==((p+4)->getValue()-1)));

        a3=(((p+3)->getValue()==((p+2)->getValue()-1))&&
        ((p+4)->getValue()==((p+3)->getValue()-1))&&
        ((p+5)->getValue()==((p+4)->getValue()-1))&&
        ((p+6)->getValue()==((p+5)->getValue()-1)));

        return (a1||a2||a3);

    }
    bool Player::ThreeOfAKind(Card array[7])//done 
    {
        Card* p =array;
        bool a1,a2,a3,a4,a5;

        a1=((p->getValue()==(p+1)->getValue())&&
        ((p+1)->getValue()==(p+2)->getValue()));
        
        a2=(((p+1)->getValue()==(p+2)->getValue())&&
        ((p+2)->getValue()==(p+3)->getValue()));

        a3=(((p+2)->getValue()==(p+3)->getValue())&&
        ((p+3)->getValue()==(p+4)->getValue()));

        a4=(((p+3)->getValue()==(p+4)->getValue())&&
        ((p+4)->getValue()==(p+5)->getValue()));

        a5=(((p+4)->getValue()==(p+5)->getValue())&&
        ((p+5)->getValue()==(p+6)->getValue()));

        return (a1||a2||a3||a4||a5);
        
    }
    bool Player::pair(Card array[7])//done.
    {
        Card* p =array;
        bool a1,a2,a3,a4,a5,a6;

        a1=((p->getValue()==(p+1)->getValue()));
        a2= ((p+1)->getValue()==(p+2)->getValue());
        a3= ((p+2)->getValue()==(p+3)->getValue());
        a4= ((p+3)->getValue()==(p+4)->getValue());
        a5= ((p+4)->getValue()==(p+5)->getValue());
        a6= ((p+5)->getValue()==(p+6)->getValue());
        return (a1||a2||a3||a4||a5||a6);

    }
    //use the quiksort algorithm when it is done.
    Card Player::highCard(Card array[7]){
        Card *p;
        return *p;

    }
    void Player::sortRank(){// biggest first done baby. isues here
        //int i;
        Card minCard;
        for(int i=0;i<7;++i){
            minCard=this->playerCards[i];
            for(int j=0;j<7;++j){
                if(this->playerCards[j].getValue()<=minCard.getValue()){
                    Card temp=this->playerCards[i];
                    this->playerCards[i]=this->playerCards[j];
                    this->playerCards[j]=temp;
                }
            }
        }
    }
    void Player::sortSuit(){// biggest first issues here.
        //int i;
        Card minCard;
        for(int i=0;i<7;++i){
            minCard=this->playerCards[i];
            for(int j=0;j<7;++j){
                if(this->playerCards[j].getSuit()<=minCard.getSuit()){
                    Card temp=this->playerCards[i];
                    this->playerCards[i]=this->playerCards[j];
                    this->playerCards[j]=temp;
                }
            }
        }
    }
    void Player::printPlayersCards(){
        for(int i=0;i<7;++i){
            playerCards[i].printCard();
        }
    }
