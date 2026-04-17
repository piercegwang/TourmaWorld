use bevy::prelude::*;
use bevy_rapier2d::prelude::*;
// use bevy::ecs::schedule::States;
// use serde::{Deserialize, Serialize};

pub struct PlayerPlugin;

impl Plugin for PlayerPlugin {
    fn build(&self, app: &mut App) {
        // app.add_systems(Startup, player_update);
        app.add_systems(Update, player_jump);
        app.add_systems(Startup, spawn_player);
        // app.add_systems(
            // (
        //         // player_respawn,
        //         // player_gravity,
                // player_update,
                // player_jump
        //         // player_control,
        //         // player_death,
        //         // player_pickups,
            // )
        //         .chain()
        //         .in_set(OnUpdate(GameState::Platforming)),
        // )
        // .add_system(player_particles)
        // .add_system(apply_player_effect)
        // .add_system(player_animation);
    }
}

#[derive(Component)]
pub struct PlayerVelocity {
    pub velocity: Vec2,
    pub on_wall: OnWall,
    pub last_on_wall: usize,
}

#[derive(PartialEq, Eq, Debug)]
pub enum OnWall {
    NotOnWall,
    OnLeft,
    OnRight,
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
        RigidBody::KinematicPositionBased,
        KinematicCharacterController {
            autostep: Some(CharacterAutostep {
                max_height: CharacterLength::Absolute(0.5),
                min_width: CharacterLength::Absolute(0.2),
                include_dynamic_bodies: true,
            }),
            snap_to_ground: Some(CharacterLength::Absolute(0.25)),
            offset: CharacterLength::Absolute(0.01),
            custom_mass: Some(10.0),
            // Enable the automatic application of impulses to the dynamic bodies
            // hit by the character along its path.
            apply_impulse_to_dynamic_bodies: true,
            ..default()
        },
        Collider::cuboid(sprite_size/2.0, sprite_size/2.0),
        GravityScale(1.0),
    ));
}

// #[derive(Component, Serialize, Deserialize, Clone, Copy)]
// pub struct PlayerStats {
//     pub float_gravity: f32,
//     pub true_gravity: f32,
//     pub player_accel: f32,
//     pub player_deccel: f32,
//     pub player_max_velocity: f32,
//     pub jump_strength: f32,
//     pub can_wall_jump: bool,
//     pub wall_jump_strength: f32,
// }

// fn player_control(

// ) {

// }

// fn player_jump(
//     mut player_info: Query<(&Player, &mut Velocity)>
// ) {

// }

// fn player_update(mut controllers: Query<&mut KinematicCharacterController>) {
//     for mut controller in controllers.iter_mut() {
//         controller.translation = Some(Vec2::new(0.0, -4.0));
//     }
// }

fn player_jump(
    // mut player_info: Query<(&Player, &mut Velocity)>,
    mut controller_outputs: Query<(&mut KinematicCharacterController, &KinematicCharacterControllerOutput)>,
    // look into https://github.com/rust-adventure/2d-platformer-sandbox-youtube-series/blob/5f046a9dcf5c97789e2ff0453765fb04f54b17cb/src/movement.rs#L241
    keyboard_input: Res<Input<KeyCode>>,
    time: Res<Time>,
) {
    // for (player, mut rb_vels) in &mut player_info {
    for (mut controller, output) in &mut controller_outputs {
        if keyboard_input.any_just_pressed([KeyCode::W, KeyCode::Up])
            && output.grounded {
            match &mut controller.translation {
                Some(vec) => {vec[1] = 20.0},
                None => {controller.translation = Some(Vec2::new(0.0, -10.0))}
            }
        }
        // // Gravity
        // if !output.grounded {
        //     match &mut controller.translation {
        //         Some(vec) => {vec[1] = vec[1] - (4.0 * time.delta_seconds())},
        //         None => {controller.translation = Some(Vec2::new(0.0, -4.0))}
        //     }
        // }
            // let down = keyboard_input.any_pressed([KeyCode::S, KeyCode::Down]);
            // let left = keyboard_input.any_pressed([KeyCode::A, KeyCode::Left]);
            // let right = keyboard_input.any_pressed([KeyCode::D, KeyCode::Right]);

            // let x_axis = -(left as i8) + right as i8;
            // let y_axis = up as i8;

            // let mut move_delta = Vec2::new(x_axis as f32, y_axis as f32);
            // // if move_delta != Vec2::ZERO {
            // //     move_delta /= move_delta.length();
            // // }
            // let rb_vels_old = rb_vels.linvel;
            // let x_vel = rb_vels_old[0] + (move_delta[0] * 150.0) * time.delta_seconds();

            // Update the velocity on the rigid_body_component,
            // the bevy_rapier plugin will update the Sprite transform.
    }
}
//
// fn player_animation(mut player: Query<(&mut TextureAtlasSprite, &PlayerVelocity)>) {
//     if let Ok((mut sprite, player)) = player.get_single_mut() {
//         if player.velocity.x > 0.0 {
//             sprite.flip_x = true;
//         }
//         if player.velocity.x < 0.0 {
//             sprite.flip_x = false;
//         }
//     }
// }
