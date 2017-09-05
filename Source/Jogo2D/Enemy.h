// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Enemy.generated.h"

UCLASS()
class JOGO2D_API AEnemy : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Move();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	void SetLife(int newLife);
	int GetLife();


private:
	UPROPERTY(EditAnywhere)
		class UPaperFlipbookComponent* Sprite;
	UPROPERTY(EditAnywhere)
		class UPaperFlipbookComponent* Idle;
	UPROPERTY(EditAnywhere)
		class UPaperFlipbookComponent* Walking;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* CollisionComp;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);


	int Life;

	float Speed;

	void ChangeSpeed();
	

	FVector InitialLocation;
	
	
};
