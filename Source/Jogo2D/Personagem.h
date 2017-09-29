// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Personagem.generated.h"

/**
 * 
 */
UCLASS()
class JOGO2D_API APersonagem : public APaperCharacter
{
	GENERATED_BODY()
	
public:

	APersonagem();

	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(class UInputComponent*
		PlayerInputComponent) override;

	virtual void Tick(float DeltaSeconds) override;

	void UpdateFlipbook();

	UFUNCTION(BlueprintCallable, Category="Shoot")
	void StartFire();
	UFUNCTION(BlueprintCallable, Category = "Shoot")
	void StopFire();
	UFUNCTION(BlueprintCallable, Category = "Shoot")
	void SwitchGun();

	void AddGunToArray(class AGun* Gun);
	int GetSelectedGun();
	TArray<class AGun*> GetGuns();

	void SetLife(float newLife);
	
	UFUNCTION(BlueprintCallable, Category = "Life")
	float GetLife();

	void SetKey(float newKey);

	float GetKey();

private:

	UPROPERTY(EditAnywhere)
		class USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere)
		class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
		class UPaperFlipbook* Idle;

	UPROPERTY(EditAnywhere)
		class UPaperFlipbook* Walking;

	UPROPERTY(EditAnywhere)
		TArray<class AGun*> Guns;

	UPROPERTY(EditAnywhere)
		int SelectedGun;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> HUDMobile;

	//UPROPERTY(EditAnywhere)
		//class UBoxComponent*PunchCollision;
	//UFUNCTION()
		//void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	
	//FTimerHandle KeepPunching;

	void Move(float Value);

	void TouchStarted(const ETouchIndex::Type FinderIndex,
		const FVector Location);

	void TouchStopped(const ETouchIndex::Type FinderIndex,
		const FVector Location);

	
	float Life;
	//void Punch();

	float Key;

	FVector InitialLocation;

};
