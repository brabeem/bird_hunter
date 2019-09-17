
class enemy {
private:
	int randDist;
	float texturHeight;
	float textureWidth;
	sf::Vector2f birdPos;
	bool isInHighlight;
	int randomSeeder;
public:
	enemy(int a, int b, int c, int e);
	void randomDistGenerate();

	void _moveBird(sf::RectangleShape& rectBird);
	void BirdAnimation(sf::RectangleShape& bird);

	bool checkIfReady(sf::RectangleShape& bird, enemy* a);
	~enemy();

	bool enemyLimit(sf::RectangleShape& bird);
};