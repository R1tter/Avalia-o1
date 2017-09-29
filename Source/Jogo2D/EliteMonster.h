// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "EliteMonster.generated.h"

/**
 * 
 */
UCLASS()
class JOGO2D_API AEliteMonster : public AEnemy
{
	GENERATED_BODY()
   
		void OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp,
			FVector NormalImpulse, const FHitResult & Hit);



 };
