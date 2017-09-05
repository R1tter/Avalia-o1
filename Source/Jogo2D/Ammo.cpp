// Fill out your copyright notice in the Description page of Project Settings.

#include "Ammo.h"
#include "Components/BoxComponent.h"
#include "PaperSpriteComponent.h"
#include "Personagem.h"
#include "Gun.h"

// Sets default values
AAmmo::AAmmo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComp"));
	CollisionComp->bGenerateOverlapEvents = true;
	CollisionComp->SetCollisionProfileName("OverlapAllDynamic");
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AAmmo::OnOverlapBegin);
	RootComponent = CollisionComp;

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	Sprite->SetCollisionProfileName("NoCollision");
	Sprite->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AAmmo::BeginPlay()
{
	Super::BeginPlay();
	
	AmmoAmount = FMath::RandRange(20, 40);
}

// Called every frame
void AAmmo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int AAmmo::GetAmmoAmount()
{
	return AmmoAmount;
}

void AAmmo::SetAmmoAmount(int NewAmmoAmount)
{
	AmmoAmount = NewAmmoAmount;
}

void AAmmo::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

	if (OtherActor != nullptr && OtherActor->IsA(APersonagem::StaticClass())) {
		APersonagem* Personagem = Cast<APersonagem>(OtherActor);
		for (int i = 0; i < Personagem->GetGuns().Num(); i++) {
			if (Personagem->GetGuns()[i]->IsA(AmmoType)) {
				Personagem->GetGuns()[i]->SetAmmoAmount(Personagem->GetGuns()[i]->GetAmmoAmount() + AmmoAmount);
				Destroy();
			}
		}
	}

}

