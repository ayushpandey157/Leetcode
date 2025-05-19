class Solution {
private:
    int horizontal=0,verticle = 0;
public:
    void shift(char move){
        switch(move){
            case 'L':
            case 'R':
                horizontalShift(move);
                break;
            case 'U':
            case 'D':
                verticleShift(move);
                break;
            default:
                cout<<"Invalid Move";
                break;
        }
    }
    void horizontalShift(char move){
        switch(move){
            case 'L': 
                this->horizontal--;
                break;
            case 'R':
                this->horizontal++;
                break;
        }
    }
    void verticleShift(char move){
        switch(move){
            case 'U':
                this->verticle++;
                break;
            case 'D':
                this->verticle--;
                break;
        }
    }
    bool judgeCircle(string moves) {
        
        for ( char move : moves){
            shift(move);
        }
        return (this->horizontal ==0 && this->verticle ==0);
        
    }
};