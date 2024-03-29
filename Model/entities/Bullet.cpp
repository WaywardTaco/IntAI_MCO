
#include "Bullet.hpp"

using namespace entities;

Bullet::Bullet(std::string name, GameObject* owner) : 
    TeamMember(name, ObjectType::BULLET, 1.f, ((TeamMember*)owner)->getTeam()) 
{
    this->attachParent(owner);
}

void Bullet::initialize(){
    this->setTexture(new AnimateTexture(TextureManager::Instance()->getTexturesOf(TextureType::BULLET)));

    GenericRenderer* renderer = new GenericRenderer(this->getName() + "Renderer");
    renderer->assignDrawable(this->sprite);
    this->attachComponent(renderer);

    this->attachComponent(new BulletMoveScript(this->getName() + "Movement"));

    this->attachComponent(new ColliderBase(this->getName() + "Collider", this->sprite->getLocalBounds().width / 2.f, this->sprite->getLocalBounds().height / 2.f));
}

void Bullet::onActivate(){
    this->setPosition(this->getParent()->getPosition());
    this->sprite->setRotation(this->getParent()->getRotation());
}

void Bullet::onRelease(){

}

GameObject* Bullet::copy(){
    return (GameObject*) new Bullet(this->getName(), this->getParent());
}

void Bullet::kill(){
    
}
