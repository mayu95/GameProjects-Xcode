//
//  Asteroid.cpp
//  BasicPhysics
//
//  Created by guyu on 2020/12/27.
//  Copyright © 2020 guyu2019. All rights reserved.
//

#include "Asteroid.hpp"
#include "MoveComponent.hpp"
#include "Game.hpp"
#include "Random.hpp"

Asteroid::Asteroid(Game* game)
    :Actor(game)
    , sc(new SpriteComponent(this))
    , mc(new MoveComponent(this))
    , mCircle(new CircleComponent(this))
{
    // 初始化一个随机的位置和方向
    Vector2 randPos = Random::GetVector(Vector2::Zero,
        Vector2(1024.0f, 768.0f));
    SetPosition(randPos);

    SetRotation(Random::GetFloatRange(0.0f, Math::TwoPi));

    sc->SetTexture(game->GetTexture("Assets/Asteroid.png"));
    mc->SetForwardSpeed(150.0f);
    
    // 设置半径
    mCircle->SetRadius(40.0f);

    // 添加到 Game 中
    game->AddAsteroid(this);
}

Asteroid::~Asteroid()
{
    GetGame()->RemoveAsteroid(this);
    if (mCircle) delete mCircle;
    if (sc) delete sc;
    if (mc) delete mc;
}
