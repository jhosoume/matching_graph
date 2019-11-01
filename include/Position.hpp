#ifndef POS
#define POS

class Position {
public:
    Position();
    Position(int skill_req);

    int skill_req;
    bool matched;
    int teacher; //id
};


#endif
