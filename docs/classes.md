# HW2 Class Design

## Duration
- **Private Data Members:**
  - `int m_total_seconds`
- **Invariants:**
  - The stored total is never negative. Seconds past 59 carry into minutes, and negative totals clamp to 0.
- **Public Functions:**
  - Constructor, `total_seconds`, `operator+`, `operator==`, `operator<<`

## Playlist
- **Private Data Members:**
  - `Track* m_tracks`
  - `int m_count`
  - `int m_capacity`
- **Invariants:**
  - $0 \le \text{m\_count} \le \text{m\_capacity}$
  - $\text{m\_capacity} \ge 1$
  - `m_tracks` points to an array of `m_capacity` tracks. No stored track has an empty title.
- **Public Functions:**
  - Constructor, Destructor, `add_track`, `size`, `total_length`, `find_track`
