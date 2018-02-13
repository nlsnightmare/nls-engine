angle = 0

function update(dt)
   __transform:rot(angle)
   __transform:scale(2,2,1)
   angle = angle + 10 * dt
end
