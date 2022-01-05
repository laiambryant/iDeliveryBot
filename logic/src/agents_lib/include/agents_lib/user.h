class user{
private:
    float x_pos;
    float y_pos;

public:
    user():x_pos(0.0), y_pos(0.0){};
    user(float x, float y):x_pos(x), y_pos(y){};
    ~user();
};

