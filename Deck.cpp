#include"Card.cpp"

class Deck{// this class i think is finished.
    Card cardDeck[4][13]; // in my deack order goes C 67,D 68,H 72 ,S 83 for the array 0,1,2,3
    bool card_used[4][13];
    public:
    void printDeck();
    Deck();
    Card getCard(int, int);
    void printboolDeck();
};

Deck::Deck(){
    for(int i=0;i<52;++i){
        cardDeck[i/13][i%13]=Card((i%13)+1);
        switch(i/13){// might have to move this to the card class. this is way more then it has to be still does the same number of inerations.
            case 0:
                cardDeck[i/13][i%13].setSuit('C');
                break;
            case 1:
                cardDeck[i/13][i%13].setSuit('D');
                break;
            case 2:
                cardDeck[i/13][i%13].setSuit('H');
                break;
            case 3:
                cardDeck[i/13][i%13].setSuit('S');
                break;
        }
        card_used[i/13][i%13]=0;
    }
}
void Deck::printDeck(){
    for(int i=0;i<52;++i){
        cardDeck[i/13][i%13].printCard();
    }
}
Card Deck::getCard(int i, int j){
    return cardDeck[i][j];
}
void Deck::printboolDeck(){
    for(int i=0;i<52;++i){
        cout << card_used[i/13][i%13] << " ";
    }
}