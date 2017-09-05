// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bullet.h"
#include "MachineGunBullet.generated.h"

/**
 * 
 */
UCLASS()
class JOGO2D_API AMachineGunBullet : public ABullet
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;
	
	
};
