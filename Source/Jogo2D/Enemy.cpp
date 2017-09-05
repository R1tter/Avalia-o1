// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"
#include "Components/BoxComponent.h"
#include "PaperFlipbookComponent.h"
#include "Personagem.h"
#include "Bullet.h"


// Sets default values
AEnemy::AEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComp"));
	CollisionComp->SetCollisionProfileName("BlockAll");
	CollisionComp->OnComponentHit.AddDynamic(this, &AEnemy::OnHit);
	RootComponent = CollisionComp;

	Sprite = CreateDefaultSubobject<UPaperFlipbookComponent>
		(TEXT("Sprite"));
//	Idle = CreateDefaultSubobject<UPaperFlipbookComponent>
//		(TEXT("Idle"));
//	Walking = CreateDefaultSubobject<UPaperFlipbookComponent>
//		(TEXT("Walking"));
	Sprite->SetupAttachment(RootComponent);
//	Idle->SetupAttachment(RootComponent);
//	Walking->SetupAttachment(RootComponent);
	Life = 4;
	Speed = 1;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation = GetActorLocation();

	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
	if (Life <= 0) {
		Destroy();
	}
}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void AEnemy::SetLife(int newLife)
{
	Life = newLife;
}
int AEnemy::GetLife()
{
	return Life;
}
void AEnemy::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit) {
	
	if (OtherActor != nullptr && OtherActor->IsA(APersonagem::StaticClass())) {
		APersonagem* Personagem = Cast<APersonagem>(OtherActor);
		Personagem->SetLife(Personagem->GetLife() - 0.1);
		UE_LOG(LogTemp, Warning, TEXT("%f"), Personagem->GetLife());
		ChangeSpeed();
	}
	if (OtherActor != nullptr && OtherActor->IsA(ABullet::StaticClass())) {
		SetLife(GetLife() - 1);
	}
}

void AEnemy::Move()
{
	if (GetActorLocation().X>=InitialLocation.X+250 || GetActorLocation().X <= InitialLocation.X -250) {
		ChangeSpeed();
	}
	
	FVector ActualLocation = GetActorLocation();
	ActualLocation.X += (2 * Speed);
	SetActorLocation(ActualLocation);
}

void AEnemy::ChangeSpeed() {
	Speed *= -1;
	if (Speed > 0) {
		Sprite->SetWorldRotation(FRotator(0.0f, 0.0f, 0.0f));
	}
	else {
		Sprite->SetWorldRotation(FRotator(0.0f, 180.0f, 0.0f));
	}
}