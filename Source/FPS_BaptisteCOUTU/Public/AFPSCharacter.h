#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AFPSCharacter.generated.h"

UCLASS()
class FPS_BAPTISTECOUTU_API AFPSCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AFPSCharacter();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    void Fire();

private:

    UPROPERTY(EditDefaultsOnly, Category = "Projectile")
    TSubclassOf<class AFPSProjectile> ProjectileClass;
    UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
    FVector MuzzleOffset;

    void MoveForward(float Value);
    void MoveRight(float Value);
    void Turn(float Value);
    void LookUp(float Value);
};
