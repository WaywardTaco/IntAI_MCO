
#include "Bullet.hpp"

using namespace entities;

Bullet::Bullet(std::string name, GameObject* owner) : 
    TeamMember(name, ObjectType::BULLET, 1.f, ((TeamMember*)owner)->getTeam()) 
{
    this->attachParent(owner);
}

void Bullet::initialize(){
    this->setTexture(new AnimateTexture(TextureManager::Instance()->getTexturesOf(TextureType::BULLET)));
    this->centerOrigin();
    this->getSprite()->setScale({8.f, 8.f});
    if(this->getTeam() == ObjectTeams::ENEMY)
        this->getSprite()->setColor(sf::Color::Red);


    GenericRenderer* renderer = new GenericRenderer(this->getName() + "Renderer");
    renderer->assignDrawable(this->sprite);
    this->attachComponent(renderer);

    this->attachComponent(new BulletMoveScript(this->getName() + "Movement"));

    this->attachComponent(new ColliderBase(this->getName() + "Collider", this->sprite->getLocalBounds().width / 2.f, this->sprite->getLocalBounds().height / 2.f));
}

void Bullet::onActivate(){
    this->setPosition(this->getParent()->getPosition());
    FacingDir facing = ((Ship*) this->getParent())->getFacing();
    ((BulletMoveScript*) this->getComponent(this->getName() + "Movement"))->setFacing(facing);
    switch(facing){
        case FacingDir::UP:
            this->sprite->setRotation(0.f);
            break;
        case FacingDir::DOWN:
            this->sprite->setRotation(180.f);
            break;
        case FacingDir::LEFT:
            this->sprite->setRotation(-90.f);
            break;
        case FacingDir::RIGHT:
            this->sprite->setRotation(90.f);
            break;

    }

}

void Bullet::onRelease(){

}

GameObject* Bullet::copy(){
    return (GameObject*) new Bullet(this->getName(), this->getParent());
}

void Bullet::kill(){
    
}
