typedef enum bot_status{
    IDLE, COLLECTING, DELIVERING,
    RETURNING, WAITING, ERROR
} bot_status;

class bot{
private:
    bot_status status;
    float x_pos;
    float y_pos;

public:
    bot(): status(IDLE), x_pos(0.0), y_pos(0.0){};
    bot(float x, float y): status(IDLE), x_pos(x), y_pos(y){};
    ~bot();
};
