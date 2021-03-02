#include"Deck.cpp"
#include<vector>

class Table{
    //the cards that are handed out dont matter on the players so no player class just cards
    // nevermind there needs to be a way to track the cards that apply to each player.(maybe a different class here this is for later)  
    Card flop1, flop2, flop3, river, turn;
    Deck table_Deck;// this includes the avalibilty and each bard.
    public:
    Card getFlop1();
    void setFlop1(Card &fl1);
    Card getFlop2();
    void setFlop2(Card &fl2);
    Card getFlop3();
    void setFlop3(Card &fl3);
    Card getRiver();
    void setRiver(Card &rvr);
    Card getTurn();
    void setTurn(Card &trn);
    bool 

};

Card Table::getFlop1(){
    return flop1;
}
    void Table::setFlop1(Card &fl1){
        flop1.setValue(fl1.getValue());
        flop1.setFace(fl1.getFace());
    }
    Card Table::getFlop2(){
        return flop2;
    }
    void Table::setFlop2(Card &fl2){
        flop2.setValue(fl2.getValue());
        flop2.setFace(fl2.getFace());
    }
    Card Table::getFlop3(){
        return flop3;
    }
    void Table::setFlop3(Card &fl3){
        flop3.setValue(fl3.getValue());
        flop3.setFace(fl3.getFace());
    }
    Card Table::getRiver(){
        return river;
    }
    void Table::setRiver(Card &rvr){
        river.setValue(rvr.getValue());
        river.setFace(rvr.getFace());
    }
    Card Table::getTurn(){
        return turn;
    }
    void Table::setTurn(Card &trn){
        turn.setValue(trn.getValue());
        turn.setFace(trn.getFace());
    }