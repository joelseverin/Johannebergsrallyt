#include "model/Checkpoint.h"

#include "Rally.h"
#include "model\PhysicsWorld.h"

#include <btBulletDynamicsCommon.h>

namespace Rally { namespace Model {

	class Finish : public Checkpoint {

	public:
		Finish(Rally::Model::PhysicsWorld& physicsWorld) : Checkpoint(physicsWorld){
			finished = false;
		};

		virtual void processCollision(btCollisionObject* colObj);

		bool finished;

		bool hasFinished(){
			return finished;
		}
	};

} }