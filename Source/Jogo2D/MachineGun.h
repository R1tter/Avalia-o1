// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gun.h"
#include "MachineGun.generated.h"

/**
 * 
 */
UCLASS()
class JOGO2D_API AMachineGun : public AGun
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;
	
	
};
