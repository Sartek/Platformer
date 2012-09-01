#ifndef PLAYER
#define PLAYER
#include "Object.hpp"
#include <SFML/Graphics.hpp>
class Player :
    public Object
{
public:
    Player();
    ~Player();
    void Initialize();
    void Update();
    void MoveUp();
    void MoveDown();
    void MoveRight();
    void MoveLeft();
    bool isOnGround();
private:
	bool _isLoaded;
	int gravity;
	int maxVelocity;
	bool onGround;
};
#endif // PLAYER
