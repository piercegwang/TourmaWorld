use bevy::prelude::*;
use bevy_rapier2d::prelude::*;

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
        .add_plugins(RapierPhysicsPlugin::<NoUserData>::pixels_per_meter(16.0))
        .add_plugins(RapierDebugRenderPlugin::default())
        .add_systems(Startup, setup)
        .add_systems(Startup, setup_physics)
        .add_systems(Startup, spawn_player)
        .add_systems(Update, player_movement)
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

fn spawn_player(
    mut commands: Commands,
    mut rapier_config: ResMut<RapierConfiguration>,
    asset_server: Res<AssetServer>
) {
    let texture = asset_server.load("character.png");

    let sprite_size = 100.0;

    // Spawn entity with `Player` struct as a component for access in movement query.
    commands.spawn((
        SpriteBundle {
            sprite: Sprite {
                custom_size: Some(Vec2::new(sprite_size, sprite_size)),
                ..Default::default()
            },
            texture,
            ..Default::default()
        },
        RigidBody::Dynamic,
        Velocity::zero(),
        Collider::cuboid(sprite_size/2.0, sprite_size/2.0),
        GravityScale(1.0),
        Player(100.0),
        AdditionalMassProperties::Mass(10.0),
    ));
}

fn setup_physics(mut commands: Commands) {
    commands
        .spawn(Collider::cuboid(500.0, 16.0))
        .insert(TransformBundle::from(Transform::from_xyz(0.0, -200.0, 0.0)));
}


fn player_movement(
    mut player_info: Query<(&Player, &mut Velocity)>,
    keyboard_input: Res<Input<KeyCode>>,
    time: Res<Time>,
) {
    for (player, mut rb_vels) in &mut player_info {
        let up = keyboard_input.any_pressed([KeyCode::W, KeyCode::Up]);
        let down = keyboard_input.any_pressed([KeyCode::S, KeyCode::Down]);
        let left = keyboard_input.any_pressed([KeyCode::A, KeyCode::Left]);
        let right = keyboard_input.any_pressed([KeyCode::D, KeyCode::Right]);

        let x_axis = -(left as i8) + right as i8;
        let y_axis = up as i8;

        let mut move_delta = Vec2::new(x_axis as f32, y_axis as f32);
        // if move_delta != Vec2::ZERO {
        //     move_delta /= move_delta.length();
        // }
        let rb_vels_old = rb_vels.linvel;
        let x_vel = rb_vels_old[0] + (move_delta[0] * 150.0) * time.delta_seconds();

        // Update the velocity on the rigid_body_component,
        // the bevy_rapier plugin will update the Sprite transform.
        rb_vels.linvel[0] =
            if x_vel > 150.0 { 150.0 } else { x_vel };
        rb_vels.linvel[1] =
            if move_delta[1] != 0.0 { move_delta[1] * 50.0 } else { rb_vels_old[1] - (100.0 * time.delta_seconds()) };
    }
}
