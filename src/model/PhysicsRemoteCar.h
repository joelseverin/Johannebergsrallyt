#ifndef RALLY_MODEL_PHYSICSREMOTECAR_H_
#define RALLY_MODEL_PHYSICSREMOTECAR_H_

#include "Rally.h"

#include <btBulletDynamicsCommon.h>

namespace Rally { namespace Model {

    class PhysicsWorld;

    class PhysicsRemoteCar_BodyMotionState : public btMotionState {
        public:
            PhysicsRemoteCar_BodyMotionState() {
                currentTransform.setIdentity();
            }

            virtual ~PhysicsRemoteCar_BodyMotionState() {
            }

            void setTargetTransform(const Rally::Vector3& targetPosition,
                    const Rally::Vector3& incomingVelocity,
                    const Rally::Quaternion& targetOrientation);

            virtual void getWorldTransform(btTransform& worldTransform) const;

            virtual void setWorldTransform(const btTransform& worldTransform);

            btTransform currentTransform;
    };

    class PhysicsRemoteCar {
        public:
            PhysicsRemoteCar();
            virtual ~PhysicsRemoteCar();
            void attachTo(PhysicsWorld& physicsWorld);

            void setTargetTransform(const Rally::Vector3& targetPosition,
                const Rally::Vector3& incomingVelocity,
                const Rally::Quaternion& targetOrientation);

            Rally::Vector3 getPosition() const;
            Rally::Quaternion getOrientation() const;
            Rally::Vector3 getVelocity() const;

        private:
            void initializeConstructionInfo();
            btDynamicsWorld* dynamicsWorld;

            btCollisionShape* bodyShape;
            PhysicsRemoteCar_BodyMotionState bodyMotionState;
            btRigidBody::btRigidBodyConstructionInfo* bodyConstructionInfo;
            btRigidBody* bodyRigidBody;
    };

} }

#endif // RALLY_MODEL_PHYSICSREMOTECAR_H_