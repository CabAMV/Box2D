#include "MyContactListener.hpp"

void MyContactListener::BeginContact(b2Contact * contact)
{
	//check if fixture A was a ball
	void* bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
	void* bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();

	if (bodyUserDataA && bodyUserDataB)
	{
		if (static_cast<GameObject*>(bodyUserDataA)->getTag() == "Vehicle")
		{
			if (static_cast<GameObject*>(bodyUserDataB)->getTag() == "Platform")
				static_cast<GameObject*>(bodyUserDataB)->startCollision();
		}

		if (static_cast<GameObject*>(bodyUserDataA)->getTag() == "Platform")
		{
			if (static_cast<GameObject*>(bodyUserDataB)->getTag() == "Vehicle")
				static_cast<GameObject*>(bodyUserDataA)->startCollision();
		}


		if (static_cast<GameObject*>(bodyUserDataA)->getTag() == "Vehicle")
		{
			if (static_cast<GameObject*>(bodyUserDataB)->getTag() == "YBox")
				static_cast<GameObject*>(bodyUserDataB)->startCollision();
		}

		if (static_cast<GameObject*>(bodyUserDataA)->getTag() == "YBox")
		{
			if (static_cast<GameObject*>(bodyUserDataB)->getTag() == "Vehicle")
				static_cast<GameObject*>(bodyUserDataA)->startCollision();
		}

		
		if (static_cast<GameObject*>(bodyUserDataA)->getTag() == "Floor")
		{
			if (static_cast<GameObject*>(bodyUserDataB)->getTag() == "YBox")
				static_cast<GameObject*>(bodyUserDataA)->startCollision();
		}

		if (static_cast<GameObject*>(bodyUserDataA)->getTag() == "YBox")
		{
			if (static_cast<GameObject*>(bodyUserDataB)->getTag() == "Floor")
				static_cast<GameObject*>(bodyUserDataB)->startCollision();
		}

	}



}
