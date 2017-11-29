#include "Enemy.hpp"
#include "../Components/Graphics/EnemyGraphicsComponent.hpp"


av::Enemy::Enemy(const sf::Vector2f l_size, const Class l_class)
	:Entity(), m_body_(l_size), m_healthbar_(sf::Vector2f(- 500.f, - 500.f)), m_class_(l_class), m_alive_(true)
{
	//Setup components
	this->m_graphics_ = new av::EnemyGraphicsComponent();

	//BODY
	this->m_body_.setOutlineThickness(2.f);
	this->m_body_.setOutlineColor(sf::Color::Black);

	//TODO: Think of a better approach for enemy spawning
	this->m_body_.setPosition(static_cast<float>(rand() % 690 + 50), static_cast<float>(rand() % 100));
	this->m_body_.setFillColor(sf::Color::Red);

	//HEALTHBAR
	this->m_healthbar_.SetPosition(this->m_body_.getPosition());
}

void av::Enemy::Update(float timestep)
{

}

void av::Enemy::HandleInput(sf::Event l_event)
{

}

void av::Enemy::Render(sf::RenderWindow& l_window)
{
	this->m_graphics_->Render(*this, l_window);
}

av::Healthbar av::Enemy::GetHealthbar()
{
	return this->m_healthbar_;
}

sf::RectangleShape av::Enemy::GetBody()
{
	return this->m_body_;
}

void av::Enemy::setPosition(const sf::Vector2f l_position)
{
	this->m_body_.setPosition(l_position);

	//Update Healthbar when Enemy position also updates
	this->m_healthbar_.SetPosition(this->m_body_.getPosition());
}

sf::Vector2f av::Enemy::getPosition() const
{
	return this->m_body_.getPosition();
}

sf::Vector2f av::Enemy::getSize() const
{
	return this->m_body_.getSize();
}

sf::RectangleShape av::Enemy::getBody()
{
	return this->m_body_;
}

void av::Enemy::TakeDamage(const sf::Uint32 l_damage)
{
	//NOTE: This is where aditional combat logic should go before the Healthbar->Minus().

	this->m_alive_ = this->m_healthbar_.Minus(l_damage);
}

bool av::Enemy::Collide(Player& l_entity) const
{
	//TODO
	return false;
}

bool av::Enemy::Collide(Bullet& l_entity)
{
	if ( ( (l_entity.getGlobalBounds().left > getPosition().x) && (getPosition().x + getSize().x > l_entity.getGlobalBounds().left) ) || \
        ((l_entity.getGlobalBounds().left + l_entity.getGlobalBounds().width > getPosition().x) && ((getPosition().x + getSize().x) > l_entity.getGlobalBounds().left + l_entity.getGlobalBounds().width))) {
            if ((getPosition().y < l_entity.getGlobalBounds().top) && (getPosition().y + getSize().y > l_entity.getGlobalBounds().top)){
                TakeDamage(l_entity.GetDamage());
                return true;
            }
        }
    return false;
}

bool av::Enemy::Collide(Enemy l_entity)
{
	return this->m_body_.getGlobalBounds().intersects(l_entity.getBody().getGlobalBounds());
}

bool av::Enemy::Collide(Entity& l_entity)
{
	return false;
}

bool av::Enemy::IsAlive()
{
    return this->m_alive_;
}
