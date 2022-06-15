use std::time::{Instant, Duration};
use sdl2::video::Window;
use sdl2::render::Canvas;
use sdl2::EventPump;
use sdl2::rect::{Rect};
use sdl2::event::{Event};
use sdl2::keyboard::Keycode;
use crate::input::*;

use crate::core::timer::Timer;

pub struct Engine {
    pub is_running: bool,
    // sdl_window: Window,
    pub sdl_renderer: Canvas<Window>,
    pub sdl_event_pump: EventPump,
    pub timer: crate::core::timer::Timer,
    pub input_state: Input,
}

impl Engine {
    pub fn clean(&self) -> bool {
        // Texture manager clean!
        // Is this function not needed because Rust cleans up everything?
        return true;
    }

    pub fn update(&mut self) {
        if self.timer.update() {}
    }

    pub fn is_running(&self) -> bool {
        self.is_running
    }

    pub fn stop(&mut self) {
        self.is_running = false;
    }

    pub fn event(&mut self) {
        for event in self.sdl_event_pump.poll_iter() {
            match event {
                Event::Quit {..} |
                Event::KeyDown { keycode: Some(Keycode::Escape), .. } => {
                    self.is_running = false;
                },
                _ => {}
            }
        }
    }

    pub fn render(&mut self) {
        let black = sdl2::pixels::Color::RGB(0, 0, 0);

        self.sdl_renderer.set_draw_color(black);
        self.sdl_renderer.clear();
    }
}

pub fn init() -> Engine {
    let ctx = sdl2::init().unwrap();
    let video_ctx = ctx.video().unwrap();

    let window  = match video_ctx
        .window("TourmaWorld", 640, 480)
        .position_centered()
        .opengl()
        .build() {
            Ok(window) => window,
            Err(err)   => panic!("failed to create window: {}", err)
        };

    let mut renderer = match window
        .into_canvas()
        .build() {
            Ok(renderer) => renderer,
            Err(err) => panic!("failed to create renderer: {}", err)
        };

    Engine {
        is_running: true,
        sdl_renderer: renderer,
        sdl_event_pump: ctx.event_pump().unwrap(),
        timer: Timer{last_time: Instant::now(),
                     delta_time: Duration::from_millis(0)},
        input_state: new(sdl_event_pump),
    }
}
