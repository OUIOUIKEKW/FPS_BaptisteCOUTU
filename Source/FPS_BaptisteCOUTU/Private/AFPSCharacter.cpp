#include "AFPSCharacter.h"
#include "AFPSProjectile.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

AFPSCharacter::AFPSCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AFPSCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AFPSCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);
    PlayerInputComponent->BindAxis("Turn", this, &AFPSCharacter::Turn);
    PlayerInputComponent->BindAxis("LookUp", this, &AFPSCharacter::LookUp);
    PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFPSCharacter::Fire);
}

void AFPSCharacter::MoveForward(float Value)
{
    if ((Controller != nullptr) && (Value != 0.0f))
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        const FVector ScaledDirection = Direction * Value * 2.0f;
        AddMovementInput(ScaledDirection, 1.0f);
    }
}

void AFPSCharacter::MoveRight(float Value)
{
    if ((Controller != nullptr) && (Value != 0.0f))
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        AddMovementInput(Direction, Value);
    }
}

void AFPSCharacter::Turn(float Value)
{
    AddControllerYawInput(Value);
}

void AFPSCharacter::LookUp(float Value)
{
    AddControllerPitchInput(Value);
}

void AFPSCharacter::Fire()
{
    if (ProjectileClass != nullptr)
    {
        UWorld* World = GetWorld();
        if (World != nullptr)
        {
            const FRotator SpawnRotation = GetControlRotation();
            const FVector SpawnLocation = GetActorLocation() + SpawnRotation.RotateVector(MuzzleOffset);

            FActorSpawnParameters ActorSpawnParams;
            ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

            AFPSProjectile* Projectile = World->SpawnActor<AFPSProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
            if (Projectile)
            {
                FVector LaunchDirection = SpawnRotation.Vector();
                Projectile->FireInDirection(LaunchDirection);
            }
        }
    }
}