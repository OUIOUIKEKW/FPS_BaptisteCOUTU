// FPSProjectile.cpp

#include "AFPSProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

AFPSProjectile::AFPSProjectile()
{
    CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
    CollisionComponent->InitSphereRadius(5.0f);
    CollisionComponent->SetCollisionProfileName(TEXT("Projectile"));
    RootComponent = CollisionComponent;
    ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
    ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
    ProjectileMovementComponent->InitialSpeed = 3000.f;
    ProjectileMovementComponent->MaxSpeed = 3000.f;
    ProjectileMovementComponent->bRotationFollowsVelocity = true;
    ProjectileMovementComponent->bShouldBounce = true;
    ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));
    ProjectileMeshComponent->SetupAttachment(RootComponent);
}

void AFPSProjectile::BeginPlay()
{
    Super::BeginPlay();
}

void AFPSProjectile::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AFPSProjectile::FireInDirection(const FVector& ShootDirection)
{
    ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}
