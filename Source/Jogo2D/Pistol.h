// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gun.h"
#include "Pistol.generated.h"

/**
 * 
 */
UCLASS()
class JOGO2D_API APistol : public AGun
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;
	
	
};
