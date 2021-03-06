#ifndef RALLY_MODEL_PHYSICSWORLD_H_
#define RALLY_MODEL_PHYSICSWORLD_H_

#include "util/Timer.h"

#include <string>
#include <vector>

class btBroadphaseInterface;
class btBulletWorldImporter;
class btDefaultCollisionConfiguration;
class btCollisionDispatcher;
class btSequentialImpulseConstraintSolver;
class btDiscreteDynamicsWorld;
class btBulletWorldImporter;

namespace Rally { namespace Model {

    class PhysicsWorld_StepCallback {
        public:
            virtual ~PhysicsWorld_StepCallback() {
            }
            virtual void willStep(float deltaTime) {
            }
            virtual void stepped(float deltaTime) {
            }
    };

    class PhysicsWorld {
        public:
            PhysicsWorld();
            virtual ~PhysicsWorld();
            void initialize(const std::string & bulletFile);
            void update(float deltaTime);

            void gravityGlitch();

            btDiscreteDynamicsWorld* getDynamicsWorld() {
                return dynamicsWorld;
            }

            void registerStepCallback(PhysicsWorld_StepCallback* stepCallback);
            void unregisterStepCallback(PhysicsWorld_StepCallback* stepCallback);
            void invokeStepCallbacks(float deltaTime, bool isPre);

        private:
            void gravityGlitchDriver();

            btBroadphaseInterface* broadphase;
            btDefaultCollisionConfiguration* collisionConfiguration;
            btCollisionDispatcher* dispatcher;
            btSequentialImpulseConstraintSolver* solver;
            btDiscreteDynamicsWorld* dynamicsWorld;
            btBulletWorldImporter* fileLoader;
            std::vector<PhysicsWorld_StepCallback*> stepCallbacks;

            Rally::Util::Timer gravityGlitchTimer;
            bool gravityGlitchActive;
    };

} }

#endif // RALLY_MODEL_PHYSICSWORLD_H_
