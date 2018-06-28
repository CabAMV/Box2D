#include "PlatformContactListener.hpp"

void PlatformContactListener::BeginContact(b2Contact * contact)
{
	//check if fixture A was a ball
	void* bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
	void* bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();

	if (bodyUserDataA && bodyUserDataB)
	{

		//activar plataforma
		if (static_cast<GameObject*>(bodyUserDataA) && static_cast<Vehicle*>(bodyUserDataB))
		{
			static_cast<GameObject*>(bodyUserDataA)->startCollision();
		}

		if (static_cast<GameObject*>(bodyUserDataB) && static_cast<Vehicle*>(bodyUserDataA))
		{
		static_cast<GameObject*>(bodyUserDataB)->startCollision();
		}

	}




}

