#include "Player.h"
#include "TextureManager.h"
#include "Input.h"

Player::Player(Properties* props): Character(props) {
    m_RigidBody = new RigidBody();
    m_Animation = new Animation();
    m_Animation->SetProps(m_TextureID, 0, 4, 200);
}

void Player::Draw() {
    m_Animation->Draw(m_Transform->x, m_Transform->y, m_Width, m_Height);
}

void Player::Clean() {
    TextureManager::GetInstance()->Clean();
}

void Player::Update(float dt) {
    m_Animation->SetProps("player", 0, 4, 200);
    m_RigidBody->UnSetForce();
    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D)) {
        SDL_Log("Key D Pushed");
        m_Animation->SetProps("player", 1, 4, 200);
        m_RigidBody->ApplyForceX(5 * FORWARD);
    }
    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A)) {
        SDL_Log("Key A Pushed");
        m_Animation->SetProps("player", 1, 4, 200, SDL_FLIP_HORIZONTAL);
        m_RigidBody->ApplyForceX(5 * BACKWARD);
    }
    m_RigidBody->Update(0.8);
    m_Transform->TranslateX(m_RigidBody->Position().x);
    // m_Transform->TranslateY(m_RigidBody->Position().y);
    m_Animation->Update();
}
