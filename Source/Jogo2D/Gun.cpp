// Fill out your copyright notice in the Description page of Project Settings.

#include "Gun.h"
#include "PaperSpriteComponent.h"
#include "Engine/World.h"
#include "Bullet.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "Components/BoxComponent.h"
#include "Personagem.h"


// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComp"));
	CollisionComp->bGenerateOverlapEvents = true;
	CollisionComp->SetCollisionProfileName("OverlapAllDynamic");
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AGun::OnOverlapBegin);
	RootComponent = CollisionComp;

	Sprite = CreateDefaultSubobject
		<UPaperSpriteComponent>(TEXT("Sprite"));
	Sprite->SetCollisionProfileName("NoCollision");
	Sprite->SetupAttachment(RootComponent);


}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
	AmmoAmount = 20;
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGun::StartFire()
{
	UE_LOG(LogTemp, Warning, TEXT("START FIRE"));
	//DoFire();
	UWorld* World = GetWorld();
	if (World != nullptr) {
		DoFire();
		GetWorldTimerManager().SetTimer(
			KeepShotting, this, &AGun::DoFire,
			TimeRate, true);
	}
}

void AGun::StopFire()
{
	UE_LOG(LogTemp, Warning, TEXT("STOP FIRE"));
	GetWorldTimerManager().ClearTimer(KeepShotting);
}

void AGun::DoFire()
{
	if (AmmoAmount > 0) {
		UWorld* World = GetWorld();
		if (World != nullptr) {
			FActorSpawnParameters SpawnParam;
			ABullet* Bullet = World->SpawnActor
				<ABullet>(BulletBP,
					RootComponent->GetComponentLocation(),
					RootComponent->GetComponentRotation(), 
					SpawnParam);
			AmmoAmount--;
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("DO FIRE"));

}

void AGun::SetAmmoAmount(int NewAmount)
{
	AmmoAmount = NewAmount;
}

int AGun::GetAmmoAmount()
{
	return AmmoAmount;
}

UBoxComponent * AGun::GetCollisionComp()
{
	return CollisionComp;
}

void AGun::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

	if (OtherActor != nullptr && OtherActor->IsA(APersonagem::StaticClass())) {
		APersonagem* Personagem = Cast<APersonagem>(OtherActor);
		Personagem->AddGunToArray(this);
	}

}

