package es.lobby.events;

import es.lobby.Main;
import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.entity.PlayerDeathEvent;

public class DeathEvent implements Listener {
    private Main plugin;

    public DeathEvent(Main plugin) {
        this.plugin = plugin;

        plugin.getServer().getPluginManager().registerEvents(this, plugin);
    }

    @EventHandler
    public void onDeath(PlayerDeathEvent event){
        Player p = event.getEntity();
        p.getInventory().clear();
        if(!(p == null)) {
            p.spigot().respawn();
        }
    }
}
