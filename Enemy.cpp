#include "Enemy.h"

Enemy::Enemy(const EnemyData& sdata)
	:data(sdata), critical(false),avoid(false),move(false)
{

}

int Enemy::Attack()
{
	if (critical)
	{
		const float C = 1.5f;
		return (int)((float)data.atk * C);
	}
	return data.atk;
}