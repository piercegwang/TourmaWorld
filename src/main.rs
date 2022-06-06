extern crate sdl2;

mod core;

// use std::process;
use sdl2::rect::{Rect};
use sdl2::event::{Event};
use sdl2::keyboard::Keycode;

fn main() {

    let mut engine = core::engine::init();

    // let mut rect = Rect::new(10, 10, 10, 10);

    while engine.is_running() {
        engine.event();
        engine.update();
        engine.render();
    }
    engine.clean();
}
