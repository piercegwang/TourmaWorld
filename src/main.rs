use bevy::prelude::*;
use bevy_rapier2d::prelude::*;

mod player;
mod lib;

use player::*;
use lib::*;

fn main() {
    App::new()
        .add_plugins(
            DefaultPlugins
                .set(ImagePlugin::default_nearest())
                .set(WindowPlugin {
                    primary_window: Some(Window {
                        title: "TourmaWorld".into(),
                        resolution: (640.0, 480.0).into(),
                        resizable: true,
                        ..default()
                    }),
                    ..default()
                })
                .build()
        )
        .add_state::<AppState>()
        .add_plugins(RapierPhysicsPlugin::<NoUserData>::pixels_per_meter(100.0))
        .add_plugins(RapierDebugRenderPlugin::default())
        .add_plugins(PlayerPlugin)
        .add_systems(Startup, setup)
        .add_systems(Startup, setup_physics)
        .run();
}

// The float value is the player movement speed in 'pixels/second'.
#[derive(Component)]
struct Player(f32);

fn setup(
    mut commands: Commands,
    mut rapier_config: ResMut<RapierConfiguration>
) {
    // Set gravity to 0.0 and spawn camera.
    rapier_config.gravity = Vec2::new(0.0, -10.0);
    commands.spawn(Camera2dBundle::default());
}

fn setup_physics(mut commands: Commands) {
    commands
        .spawn(Collider::cuboid(500.0, 16.0))
        .insert(TransformBundle::from(Transform::from_xyz(0.0, -200.0, 0.0)))
        .insert(RigidBody::Fixed);
}


