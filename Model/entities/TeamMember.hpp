
#pragma once

#include "Entity.hpp"
#include "../enums/ObjectTeams.hpp"

namespace entities {
    class TeamMember : public Entity {
        private:
            ObjectTeams team;
            float 
                maxHealth, 
                currHealth;
        public:
            TeamMember(std::string name, ObjectType type, float maxHealth, ObjectTeams team);

            virtual void initialize();
            virtual GameObject* copy();

            virtual void kill() = 0;

            ObjectTeams getTeam();
            float getHealth();
            float getMaxHealth();
            void resetHealth();
            void heal(float amount);
            void damage(float amount);
    };
}