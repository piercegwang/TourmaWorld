use std::time::{Instant, Duration};

const TICKS_PER_SECOND:u64 = 20;
const MILLIS_PER_TICK:u64 = 1000/TICKS_PER_SECOND;

pub struct Timer {
    pub last_time: Instant,
    pub delta_time: Duration,
}

impl Timer {
    pub fn update(&mut self) -> bool {
        self.delta_time = self.delta_time + self.last_time.elapsed();
        self.last_time = Instant::now();
        if self.delta_time > Duration::from_millis(MILLIS_PER_TICK) {
            self.delta_time = self.delta_time - Duration::from_millis(MILLIS_PER_TICK);
            return true;
        }
        false
    }
}
