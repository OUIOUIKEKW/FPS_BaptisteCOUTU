
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AFPSProjectile.generated.h"

UCLASS()
class FPS_BAPTISTECOUTU_API AFPSProjectile : public AActor
{
    GENERATED_BODY()

public:
    AFPSProjectile();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
    void FireInDirection(const FVector& ShootDirection);

private:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    class USphereComponent* CollisionComponent;
    UPROPERTY(VisibleAnywhere, Category = "Components")
    class UProjectileMovementComponent* ProjectileMovementComponent;
    UPROPERTY(VisibleAnywhere, Category = "Components")
    class UStaticMeshComponent* ProjectileMeshComponent;
};